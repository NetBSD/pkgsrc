# $NetBSD: Makefile,v 1.27 2020/04/20 08:37:14 wiz Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-m4-/}
COMMENT=	Autoconf/automake m4 files for GNU NLS library
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/aclocal

GNULIB_M4_FILES=		\
	codeset.m4		\
	extern-inline.m4	\
	host-cpu-c-abi.m4	\
	lcmessage.m4		\
	lib-ld.m4		\
	lib-link.m4		\
	lib-prefix.m4		\
	lock.m4			\
	threadlib.m4		\
	wchar_t.m4		\
	wint_t.m4

do-install:
	${INSTALL_DATA} ${WRKSRC}/gettext-runtime/m4/*.m4 \
		${DESTDIR}${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/m4/*.m4 \
		${DESTDIR}${PREFIX}/share/aclocal
.for i in ${GNULIB_M4_FILES}
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/gnulib-m4/${i} \
	    ${DESTDIR}${PREFIX}/share/aclocal
.endfor

.include "../../mk/bsd.pkg.mk"
