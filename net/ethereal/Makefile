# $NetBSD: Makefile,v 1.45 2001/04/30 04:16:10 jlam Exp $
#

ETHEREAL_VERSION=	0.8.16
DISTNAME=		ethereal-${ETHEREAL_VERSION}
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.ethereal.com/
COMMENT=		Network protocol analyzer

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		ucd-snmp>=4.1.2:../../net/ucd-snmp
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

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
