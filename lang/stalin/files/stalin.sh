#! /bin/sh

exec @PREFIX@/lib/stalin/stalin -On -I @PREFIX@/lib/stalin -I @PREFIX@/include -I @LOCALBASE@/include -I @LOCALBASE@/lib -I @X11BASE@/lib -I @X11BASE@/include $@
