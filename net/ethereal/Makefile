# $NetBSD: Makefile,v 1.50 2001/09/23 21:25:49 tron Exp $

DISTNAME=		ethereal-0.8.19
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
LIBS+=			-lcrypto

PLIST_SUBST+=		PKGVERSION="${PKGVERSION}"

.include "../../mk/bsd.pkg.mk"
