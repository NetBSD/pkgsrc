# $NetBSD: Makefile,v 1.4 2001/12/19 15:38:00 taca Exp $
#

DISTNAME=	bkpupsd-2.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jepro.co.jp/pub/jepro/misc/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.jepro.co.jp/
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
