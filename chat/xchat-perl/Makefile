# $NetBSD: Makefile,v 1.3 2008/05/25 14:45:16 tron Exp $

.include "../../chat/xchat/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-perl-/}
OWNER=		tron@NetBSD.org

COMMENT=		Perl scripting plugin for XChat

DEPENDS+=		xchat>=2.0.0:../../chat/xchat

BUILD_DIRS?=		plugins/perl

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--enable-perl
CONFIGURE_ARGS+=	--disable-python

USE_PERL5=	YES
USE_TOOLS+=	perl

.include "../../lang/perl5/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/alt_completion.pl \
		${PREFIX}/share/examples/xchat
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perl.html \
		${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perldocs.html \
		${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
