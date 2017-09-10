# $NetBSD: Makefile,v 1.35 2017/09/10 14:13:15 joerg Exp $
#

DISTNAME=	bkpupsd-2.2.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.back-street.net/pub/misc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not exist
COMMENT=	Simple UPS daemon for BK-Pro, BK and FREQUPS A/F series

USE_BSD_MAKEFILE=	yes
MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS=	libexec/bkpupsd sbin ${PKGMANDIR}/cat5 \
			${PKGMANDIR}/cat8 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			share/doc/bkpupsd share/examples/bkpupsd

# Original program assumes BSD code base.
ONLY_FOR_PLATFORM= NetBSD-*-*

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/bkpupsd
MAKE_ENV+=	DEFAULT_DEVICE=${DEFAULT_SERIAL_DEVICE:Q} DOCDIR=${DOCDIR:Q} \
		RCD_SCRIPTS_EXAMPLEDIR=${RCD_SCRIPTS_EXAMPLEDIR:Q}

MESSAGE_SUBST+=	DOCDIR=${DOCDIR}

EGDIR=		${PREFIX}/share/examples/bkpupsd
CONF_FILES=	${EGDIR}/upstab ${PKG_SYSCONFDIR}/upstab

RCD_SCRIPTS=	bkpupsd
RCD_SCRIPT_SRC.bkpupsd=	# need to avoid automatic handling

pre-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DESTDIR}${DOCDIR}

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-traditional
.endif

.include "../../mk/bsd.pkg.mk"
