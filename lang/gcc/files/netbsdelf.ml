# Elf with shared libm, so we can link it into the shared libstdc++.

ARLIB   = libstdc++.a.`echo $(VERSION) | sed 's/\([0-9]*[.][0-9]*\).*/\1/'`
SHLIB   = libstdc++.so.`echo $(VERSION) | sed 's/\([0-9]*[.][0-9]*\).*/\1/'`
MSHLINK = libstdc++.so.`echo $(VERSION) | sed 's/\([0-9]*\).*/\1/'`

LIBS    = $(ARLIB) $(ARLINK) $(SHLIB) $(SHLINK) mshlink
SHFLAGS = -Wl,-soname,$(MSHLINK)
SHDEPS  = -lm
DEPLIBS = ../$(SHLIB)
