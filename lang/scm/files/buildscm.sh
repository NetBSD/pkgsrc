#! /bin/sh
# unix (unix) script created by SLIB/batch Thu Jul 17 21:20:04 2003
# ================ Write file with C defines
rm -f scmflags.h
echo '#define IMPLINIT "@PREFIX@/share/scm/Init5e3.scm"'>>scmflags.h
echo '#define INITS init_sc2();init_ramap();init_gsubr();init_ioext();init_posix();init_record();init_rgx();init_socket();init_unix();'>>scmflags.h
echo '#define COMPILED_INITS @COMPILED_INITS@'>>scmflags.h
echo '#define ARRAYS'>>scmflags.h
echo '#define BIGNUMS'>>scmflags.h
echo '#define CAUTIOUS'>>scmflags.h
echo '#define CHEAP_CONTINUATIONS'>>scmflags.h
echo '#define CAN_DUMP'>>scmflags.h
echo '#define ENGNOT'>>scmflags.h
echo '#define FLOATS'>>scmflags.h
echo '#define MACRO'>>scmflags.h
echo '#define CCLO'>>scmflags.h
echo '#define TICKS'>>scmflags.h
# ================ Compile C source files
${CC} ${CFLAGS} -c -Wall ${SRCS}
# ================ Link C object files
mv -f scm scm~
${CC} ${LDFLAGS} -o scm ${OBJS} -lm -lreadline ${LIBS}
