# $NetBSD: Makefile,v 1.56 2002/03/22 06:27:17 martti Exp $

DISTNAME=		ethereal-0.9.2
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
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_DIR} \
			--with-ucdsnmp=${BUILDLINK_DIR}
LIBS+=			-lcrypto

.include "../../x11/gtk/buildlink.mk"
.include "../ucd-snmp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
