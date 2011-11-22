#!/usr/bin/perl 

if (($ARGV[0] =~ /Cached:/) || ($ARGV[0] =~ /SwapFree:/)) { 
	open(PROCESS, "pstat -ks |"); 
	$s = 0; 
	while (<PROCESS>) { 
		if (!/^Device/) { 
			split(); 
			$s += $_[3]; 
		} 
	} 
	print "$s"; 
} 
else { # $ARGV[0] is Buffers:, MemFree:, or anything else 
	open(PROCESS, "vmstat -H |"); 
	while (<PROCESS>) { 
		if (!/p/) { # the numbers line happens not to have "p" 
			split(); 
			print("$_[4]"); 
		} 
	} 
} 
close(PROCESS); 
