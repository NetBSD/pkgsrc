# $NetBSD: Makefile,v 1.59 2002/04/20 18:46:08 fredb Exp $

DISTNAME=		ethereal-0.9.3
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.ethereal.com/
COMMENT=		Network protocol analyzer

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
