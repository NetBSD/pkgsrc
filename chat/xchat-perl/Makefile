# $NetBSD: Makefile,v 1.10 2011/08/14 07:38:55 obache Exp $

.include "../../chat/xchat/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-perl-/}
PKGREVISION=		2
OWNER=			tron@NetBSD.org

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
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/examples/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/alt_completion.pl \
		${DESTDIR}/${PREFIX}/share/examples/xchat
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perl.html \
		${DESTDIR}/${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perldocs.html \
		${DESTDIR}/${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
