#!@SH@
#
# Client program to allow local non-root users to see the queue.
# Requires that the corresponding server program be running. From
# Steinar Haug.

exec @LOCALBASE@/bin/tcpclient -RHl0 -- 127.0.0.1 20025 @SH@ -c 'exec @CAT@ <&6'
