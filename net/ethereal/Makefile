# $NetBSD: Makefile,v 1.40 2001/01/12 12:13:10 itojun Exp $
#

ETHEREAL_VERSION=	0.8.15
DISTNAME=		ethereal-${ETHEREAL_VERSION}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.ethereal.com/

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
#DEPENDS+=		ucd-snmp>=4.1.2:../../net/ucd-snmp
BUILD_DEPENDS+=		${PERL5}:../../lang/perl5-base

USE_X11=		YES
USE_SSL=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}" \
			--with-ucdsnmp=${LOCALBASE}
CONFIGURE_ENV+=		LIBS="${LIBS}"
LIBS+=			-lcrypto

PLIST_SUBST+=		ETHEREAL_VERSION=${ETHEREAL_VERSION}

post-install:
	${INSTALL_MAN} ${WRKSRC}/editcap.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ethereal.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tethereal.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
