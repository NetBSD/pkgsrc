# $NetBSD: Makefile,v 1.6 2003/03/12 16:43:45 taca Exp $
#

DISTNAME=	bkpupsd-2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jone-system.com/pub/misc/ \
		ftp://ftp.back-street.net/pub/misc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	# not exist
COMMENT=	simple UPS daemon for BK-Pro, BK series and FREQUPS F series

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/bkpupsd
PKGRCDIR=	${PREFIX}/etc/rc.d
ETCDIR=		${DESTDIR}/etc
MAKE_ENV+=	DEFAULT_DEVICE=${DEFAULT_SERIAL_DEVICE} DOCDIR=${DOCDIR}

MESSAGE_SUBST+=	DOCDIR=${DOCDIR} ETCDIR=${ETCDIR} PKGRCDIR=${PKGRCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
