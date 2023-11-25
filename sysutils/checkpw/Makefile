# $NetBSD: Makefile,v 1.3 2023/11/25 19:06:50 schmonz Exp $

DISTNAME=		checkpw-1.03
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=checkpw/checkpw/${DISTNAME}/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://checkpw.sourceforge.net/checkpw/
COMMENT=		Password-checking tools for password files in Maildir
LICENSE=		public-domain

INSTALLATION_DIRS+=	bin share/doc/${PKGBASE} share/examples/${PKGBASE}

post-extract:
	cd ${WRKSRC};							\
	${MV} INSTALL INSTALL.txt

post-install:
	cd ${WRKSRC};							\
	${INSTALL_DATA} INSTALL.txt					\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/INSTALL;	\
	for f in pop rules apop both multipw multidir; do		\
		${INSTALL_DATA} run-$$f				\
			${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
