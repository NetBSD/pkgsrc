#!@SH@

rm -f /dev/tap /dev/tap0 /dev/tap1 /dev/tap2 /dev/tap3
mknod /dev/tap c $3 0xfffff
mknod /dev/tap0 c $3 0
mknod /dev/tap1 c $3 1
mknod /dev/tap2 c $3 2
mknod /dev/tap3 c $3 3
