# a.out with shared libm, so we can link it into the shared libstdc++.

ARLIB   = libstdc++.a.`echo $(VERSION) | sed 's/\([0-9]*[.][0-9]*\).*/\1/'`
SHLIB   = libstdc++.so.`echo $(VERSION) | sed 's/\([0-9]*[.][0-9]*\).*/\1/'`

LIBS    = $(ARLIB) $(ARLINK) $(SHLIB)
SHDEPS  = -lm
DEPLIBS = ../$(SHLIB)
