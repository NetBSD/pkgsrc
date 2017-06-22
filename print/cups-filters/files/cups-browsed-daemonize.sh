#!/bin/sh

# cups-browsed itself doesn't daemonize
( cd /; @PREFIX@/sbin/cups-browsed </dev/null >/dev/null 2>&1 & echo $! >@VARBASE@/run/cups-browsed.pid ) &
