# $NetBSD: Makefile,v 1.6 2020/05/23 21:32:15 schmonz Exp $

DISTNAME=		qmail-autoresponder-2.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/qmail-autoresponder/
COMMENT=		Rate-limited autoresponder for qmail
LICENSE=		gnu-gpl-v2

DEPENDS+=		qmail-[0-9]*:../../mail/qmail

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}

DJB_RESTRICTED=		no
DJB_ERRNO_HACK=		no
DJB_MAKE_TARGETS=	no
BUILD_TARGET=		all

LDFLAGS.SunOS+=		-lsocket

.include "options.mk"

pre-configure:
	${TOUCH} ${WRKSRC}/conf-bgincs ${WRKSRC}/conf-bglibs

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
