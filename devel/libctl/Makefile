# $NetBSD: Makefile,v 1.26 2009/07/08 16:32:38 joerg Exp $

DISTNAME=	libctl-2.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	share/doc/libctl
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING COPYRIGHT ChangeLog 	\
		NEWS README ${DESTDIR}${PREFIX}/share/doc/libctl/

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
