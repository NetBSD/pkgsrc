# $NetBSD: Makefile,v 1.1 2014/06/23 22:25:39 christos Exp $

.include <bsd.own.mk>

WARNS=0

CPPFLAGS+= -DBSD44 -DCK_CURSES -DCK_DTRCD -DCK_DTRCTS -DCK_PAM -DFNFLOAT
CPPFLAGS+= -DHAVE_OPENPTY -DHERALD=\"NetBSD\" -DTCPSOCKET -DTPUTSARGTYPE=int
CPPFLAGS+= -DUSE_STRERROR -DZLIB -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE
CPPFLAGS+= -DNO_DCL_INET_ATON

.if ${MKCRYPTO} == "yes"
CPPFLAGS+= -DCK_AUTHENTICATION -DCK_CAST -DCK_DES -DCK_ENCRYPTION
CPPFLAGS+= -DCK_KERBEROS -DCK_SSL -DKRB5 -DLIBDES -DOPENSSL_100 -DHEIMDAL
CPPFLAGS+= -DKTARGET='" netbsd+krb5+openssl+zlib"'
CPPFLAGS+= -I/usr/include/krb5

LDADD+= -lcrypt -lcrypto -ldes -lgssapi -lkrb5 -lssl
DPADD+= ${LIBCRYPT} ${LIBCRYPTO} ${LIBDES} ${LIBGSSAPI} ${LIBKRB5} ${LIBSSL}

COPTS.ckuath.c= -Wno-error=deprecated-declarations

.else
CPPFLAGS+= -DKTARGET='" netbsd+zlib"'
.endif

LDADD+=-lpam -lutil -lcurses -lz -lm
DPADD+=${LIBPAM} ${LIBUTIL} ${LIBCURSES} ${LIBZ} ${LIBM}
CPPFLAGS+=-std=c89

.PATH: ${.CURDIR}/../dist

PROG=	kermit
SRCS+=	ck_crp.c ck_ssl.c ckcfn2.c ckcfn3.c ckcfns.c ckcftp.c ckclib.c \
	ckcmai.c ckcnet.c ckcpro.c ckctel.c ckcuni.c ckuath.c ckucmd.c \
	ckucns.c ckudia.c ckufio.c ckupty.c ckuscr.c ckusig.c ckutio.c \
	ckuus2.c ckuus3.c ckuus4.c ckuus5.c ckuus6.c ckuus7.c ckuusr.c \
	ckuusx.c ckuusy.c ckuxla.c

CLEANFILES+=kermit.1

.include <bsd.prog.mk>

kermit.1: ${.CURDIR}/../dist/ckuker.nr
	@cp ${.ALLSRC} ${.TARGET}
