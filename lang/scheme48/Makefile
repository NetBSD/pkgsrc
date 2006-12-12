# $NetBSD: Makefile,v 1.29 2006/12/12 23:17:40 rillig Exp $

DISTNAME=		scheme48-1.3
CATEGORIES=		lang
MASTER_SITES=		http://s48.org/1.3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://s48.org/
COMMENT=		The Scheme Underground's implementation of R5RS

NOT_FOR_PLATFORM=	*-*-alpha	# *severe* problems.  Bus error, alignment

GNU_CONFIGURE=		yes
BUILD_TARGET=		enough

MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/scheme48
	cd ${WRKSRC:Q}/doc && ${INSTALL_DATA} *.txt *.ps \
		${PREFIX:Q}/share/doc/scheme48
	${INSTALL_DATA} ${WRKSRC:Q}/COPYING ${PREFIX:Q}/share/doc/scheme48
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/scheme48/html
	${INSTALL_DATA} ${WRKSRC:Q}/doc/html/* \
		${PREFIX:Q}/share/doc/scheme48/html

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
