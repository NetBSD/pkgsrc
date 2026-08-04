# $NetBSD: Makefile,v 1.22 2026/08/04 20:29:03 wiz Exp $

DISTNAME=	vscmV1R2
PKGNAME=	vscm-1.4
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vscm/}
MASTER_SITES+=	ftp://ftp.cs.indiana.edu/pub/scheme-repository/imp/vscm/

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
