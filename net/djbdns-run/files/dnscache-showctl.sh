#!@SH@
# (c) Copyright 2001-2002 Jonathan de Boyne Pollard. All rights reserved. "Moral" rights asserted.
# Permission is hereby granted to distribute this script unmodified.
for i do (
	cd "$i"
	echo "$i" | sed -e 's/./*/g'
	echo "$i"
	echo "$i" | sed -e 's/./*/g'
	echo
	echo '+++ Configuration options:'
	egrep '[A-Za-z0-9_]+=' run
	( cd env 2>/dev/null && grep "^" /dev/null * )
	echo
	echo '+++ Authorised client IP address prefixes:'
	ls -1 root/ip
	echo
	echo '+++ Hardwired content server IP addresses:'
	cd root/servers && grep "^" /dev/null *
	echo
); done
