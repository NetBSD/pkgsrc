#!/usr/bin/env perl

#####################################################
# Program to check to make sure spamd is running and report back to nrpe for 
# nagios. The variable that most folks will want to change is "$spamc" which
# is the location of the spamc program.
# Created: 2006-11-29
# Version: 1.6.0
# Author: Erinn Looney-Triggs
# Revised: 2009-02-18
# Revised by: Martin Mares
# Revision history: 
# 1.6.0: Added remote host checks and Time::HiRes thanks to Martin Mares. Also
# added a revision history, you have to start somewhere.
#####################################################

use English qw( -no_match_vars );
use Getopt::Long;            #Grab command line switches
use Pod::Usage;
use POSIX qw( WIFEXITED );   #Fix system call's strange return values
use strict;                  #Do it right
use Switch;                  #Standard perl 5.8 module to use switch statement
use Time::HiRes;             #High-precision timers
use warnings;

my $timeout = 10;                           #Default timeout of 10 seconds
my $return_code;                            #Return code holder
my $spamc = '/usr/local/perl/bin/spamc';    #Location of spamc
my $host;
my $port;
my $VERSION = '1.6.0';                      #Version number

Getopt::Long::Configure( 'bundling', 'gnu_compat', );

GetOptions( 'man'           => sub { pod2usage(-verbose  => 2) },
            'spamc|s=s'     => \$spamc,
            'timeout|t=i'   => \$timeout,
            'host|H=s'      => \$host,
            'port|p=i'      => \$port,
            'version|V'     => sub { VersionMessage() },
            'help|h'        => sub { pod2usage(1) },
);

#Make sure spamc exists and if not give back a nagios warning
if ( !-e $spamc ) {
    print "$spamc does not exist.\n";
    exit 2;
}

#Which command we should run
my $opts = "-x";
$opts .= " -d $host" if defined $host;
$opts .= " -p $port" if defined $port;
my $spamc_command = "echo foo | $spamc $opts > /dev/null 2>&1";

#Timer operation. Times out after $timeout seconds.
my $start_time = Time::HiRes::time;
eval {

    #Set the alarm and set the timeout
    local $SIG{ALRM} = sub { die "alarm\n" };
    alarm $timeout;

    #Run the command
    WIFEXITED( system $spamc_command)
        or die "Could not run $spamc_command\n";
    $return_code = $CHILD_ERROR;

    alarm 0;
};

my $elapsed_time = Time::HiRes::time - $start_time;

#Test return value and exit if eval caught the alarm
if ($EVAL_ERROR) {
    if ( $EVAL_ERROR eq "alarm\n" ) {
        print "Operation timed out after $timeout seconds.\n";
        exit 2;
    }
    else {
        print "An unknown error has occured: $EVAL_ERROR \n";
        exit 3;
    }
}

#Divide by 256 or bitshift right by 8 to get the original error code
$return_code >>= 8;

#Parse the errors and give Nagios parsible error codes and messages
switch ($return_code) {
    case 0  { printf "OK - %.3fs response time\n", $elapsed_time; exit 0; }
    case 64 { print "Command line usage error\n";               exit 1; }
    case 65 { print "Data format error\n";                      exit 1; }
    case 66 { print "Cannot open input\n";                      exit 1; }
    case 67 { print "Addressee unknown\n";                      exit 1; }
    case 68 { print "Host name unknown\n";                      exit 1; }
    case 69 { print "Spamd service unavailable\n";              exit 2; }
    case 70 { print "Internal software error\n";                exit 2; }
    case 71 { print "System error (e.g., can't fork)\n";        exit 2; }
    case 72 { print "Critical OS file missing\n";               exit 2; }
    case 73 { print "Can't create (user) output file\n";        exit 1; }
    case 74 { print "Input/output error\n";                     exit 1; }
    case 75 { print "Temp failure; user is invited to retry\n"; exit 1; }
    case 76 { print "Remote error in protocol\n";               exit 2; }
    case 77 { print "Permission denied\n";                      exit 1; }
    case 78 { print "Configuration error\n";                    exit 1; }
    else    { print "An unknown error has occured in $spamc\n"; exit 3; }
}

#Version message information displayed in both --version and --help
sub main::VersionMessage {
    print <<"EOF";
This is version $VERSION of check_spamd.

Copyright (c) 2009 Erinn Looney-Triggs (erinn.looneytriggs\@gmail.com). 
All rights reserved.

This module is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License. 
See http://www.fsf.org/licensing/licenses/gpl.html

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

EOF

    exit 1;
}
__END__

=head1 NAME

check_spamd - Checks the status of SpamAssassin's spamd daemon via spamc.

=head1 VERSION

This documentation refers to check_spamd version 1.6.0

=head1 USAGE

check_spamd.pl

=head1 REQUIRED ARGUMENTS

None

=head1 OPTIONS

--host    (-H)     Set the host on which spamd runs (default: localhost).
--port    (-p)     Set TCP port number of spamd.
--spamc   (-s)     Set the location of the spamc executable. 
--timeout (-t)     Sets the timeout, defaults to 10 seconds.


=head1 DESCRIPTION
 
This is a Nagios plugin that runs spamc to check the status of the spamd
daemon. It then parses the resultant exit codes and NRPE grabs them.

The plugin is able to check spamd either at the local host or over the network.

=head1 DIAGNOSTICS

=head2 spamc does not exist:

The spamc program does not exist where the plugin is looking for it. By 
default check_spamd looks for spamc in /usr/local/perl/bin/spamc. This may 
not be the location of spamc on your system. Change the variable $spamc to 
fix this issue.

=head1 CONFIGURATION AND ENVIRONMENT

spamc should be available on the checking system.
 
=head1 DEPENDENCIES
 
    check_spamd depends on the following modules:
    Switch          Standard Perl 5.8 module
    POSIX           Standard Perl 5.8 module
    Getopt::Std     Standard Perl 5.8 module
    Time::HiRes     Standard Perl 5.8 module
    
=head1 INCOMPATIBILITIES

None known yet.

=head1 BUGS AND LIMITATIONS

Bugs, never heard of 'em ;).
If you encounter any bugs let me know. (erinn.looneytriggs@gmail.com)

=head1 AUTHOR

Erinn Looney-Triggs (erinn.looneytriggs@gmail.com)

=head1 LICENCE AND COPYRIGHT

Copyright (c) 2009 Erinn Looney-Triggs (erinn.looneytriggs@gmail.com). 
All rights reserved.

This module is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License. 
See L<http://www.fsf.org/licensing/licenses/gpl.html>.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
