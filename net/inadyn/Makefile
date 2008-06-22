# $NetBSD: Makefile,v 1.1.1.1 2008/06/22 04:52:39 dmcmahill Exp $
#

DISTNAME=	inadyn.v1.96.2
PKGNAME=	inadyn-1.96.2
CATEGORIES=	net
MASTER_SITES=	http://www.inatech.eu/inadyn/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inatech.eu/inadyn/
COMMENT=	Dynamic DNS client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

LIBS.SunOS=	-lsocket -lnsl
MAKE_ENV+=	TARGET_ARCH=pkgsrc

WRKSRC=		${WRKDIR}/inadyn
MAKE_FILE?=	makefile

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

# do the dos to unix thing before patching to make it easier to
# try changes (don't need the dos2unix and unix2dos in the mix)
pre-patch:
	cd ${WRKSRC}; for file in man/inadyn.conf.5 man/inadyn.8 src/dyndns.h ; do \
		${SED}  -e "s|/etc|${PKG_SYSCONFDIR}|g"                            \
			$${file} > $${file}.orig;                                  \
		${CP} -f $${file}.orig $${file};                                   \
	done
	cd ${WRKSRC}/src && for f in * ; do                                        \
		if ${TEST} -f $$f ; then                                              \
			mv $$f $$f.bak ; cat $$f.bak | ${TR} -d '\r' > $$f ;       \
			rm $$f.bak ;                                               \
		fi                                                                 \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pkgsrc/inadyn ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
