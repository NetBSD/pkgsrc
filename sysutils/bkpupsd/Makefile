# $NetBSD: Makefile,v 1.12 2004/12/14 15:09:03 taca Exp $
#

DISTNAME=	bkpupsd-2.1.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jone-system.com/pub/misc/ \
		ftp://ftp.back-street.net/pub/misc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not exist
COMMENT=	Simple UPS daemon for BK-Pro, BK series and FREQUPS F series

# Original program assumes BSD code base.
ONLY_FOR_PLATFORM= NetBSD-*-*

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/bkpupsd
MAKE_ENV+=	DEFAULT_DEVICE=${DEFAULT_SERIAL_DEVICE} DOCDIR=${DOCDIR}

MESSAGE_SUBST+=	DOCDIR=${DOCDIR}

EGDIR=		${PREFIX}/share/examples/bkpupsd
CONF_FILES=	${EGDIR}/upstab ${PKG_SYSCONFDIR}/upstab

RCD_SCRIPTS=	bkpupsd

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
