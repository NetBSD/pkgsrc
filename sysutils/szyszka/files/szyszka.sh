#!/bin/sh
if [ -f /usr/X11R7/lib/libEGL.so ] && [ -z "$LD_PRELOAD" ] && \
  nm /usr/X11R7/lib/libGL.so | grep -Fq "B _glapi_tls_Dispatch"; then
    # Workaround for PR#57445/50277 for netbsd-9 & netbsd-10 pre 2023-08-05
    # This may not avoid a crash 100% of the time, but changes at least some
    # cases of 100% crash on startup to "have not yet seen crash on startup"
    echo "Applying libEGL LD_PRELOAD workaround for NetBSD" >&2
    export LD_PRELOAD=/usr/X11R7/lib/libEGL.so
fi
exec @PREFIX@/libexec/szyszka/szyszka "$@"
