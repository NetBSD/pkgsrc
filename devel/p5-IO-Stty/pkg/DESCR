
	The two perl items in this package are an stty shell script and a 
module for setting terminal parameters. to use the Stty.pm module stuff it in
your $PERL_LIB_DIR/site_perl/IO directory. In your scripts do:

     use IO::Stty;
     IO::Stty::stty(\*TTYHANDLE, @modes);

     This has not been tailored to the IO::File stuff but will work with it as
indicated. Before you go futzing with term parameters it's a good idea to grab
the current settings and restore them when you finish.

	Example:

     use IO::Stty;
     $old_mode=IO::Stty::stty(\*STDIN,'-g');
     # Turn off echoing.
     IO::Stty::stty(\*STDIN,'-echo');
     # Do whatever.. grab input maybe?
     $read_password = <>;
     # Now restore the old mode.
     IO::Stty::stty(\*STDIN,$old_mode);
     # What settings do we have anyway?
     print IO::Stty::stty(\*STDIN,'-a');


     This is use at your own risk software. Do anything you want with it except
blame me for it blowing up your machine because it's full of bugs.
     The file stty.txt indicates what functions are supported. Standard POSIX
stuff. If any of the settings are wrong and you actually know what some of
these extremely arcane settings (like what 'sane' should be in POSIX land)
really should be, let me know.

11-08-97	Austin Schutz<tex@habit.com>
