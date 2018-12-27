# $NetBSD: Makefile,v 1.23 2018/12/27 15:09:53 joerg Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-m4-/}
PKGREVISION=	1
COMMENT=	Autoconf/automake m4 files for GNU NLS library
LICENSE=	gnu-gpl-v2

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/aclocal

do-install:
	${INSTALL_DATA} ${WRKSRC}/gettext-runtime/m4/*.m4 \
		${DESTDIR}${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/m4/*.m4 \
		${DESTDIR}${PREFIX}/share/aclocal
.	for i in lib-ld.m4 lib-link.m4 lib-prefix.m4
	    ${INSTALL_DATA} ${WRKSRC}/gettext-tools/gnulib-m4/${i} \
		${DESTDIR}${PREFIX}/share/aclocal
.	endfor

.include "../../mk/bsd.pkg.mk"
