# $NetBSD: Makefile,v 1.20 2012/12/21 04:23:45 dholland Exp $

DISTNAME=	vscmV1R2
PKGNAME=	vscm-1.4
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vscm/} \
	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/vscm/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cs.princeton.edu/~blume/vscm/
COMMENT=	Portable scheme implementation

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin lib/vscm share/doc/vscm

post-patch:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/path.h >${WRKSRC}/path.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vscm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/.scheme-boot				\
		${DESTDIR}${PREFIX}/lib/vscm/vscm-boot
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL DESCRIPTION	\
		${DESTDIR}${PREFIX}/share/doc/vscm

.include "../../mk/bsd.pkg.mk"
