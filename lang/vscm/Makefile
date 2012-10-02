# $NetBSD: Makefile,v 1.19 2012/10/02 20:11:57 asau Exp $

DISTNAME=	vscmV1R2
PKGNAME=	vscm-1.4
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
