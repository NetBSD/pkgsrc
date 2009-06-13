# $NetBSD: Makefile,v 1.3 2009/06/13 06:46:45 rillig Exp $

DISTNAME=		Gtk2-GladeXML-1.007
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Gtk2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Gtk2-GladeXML/
COMMENT=		Create user interfaces directly from Glade XML files

PERL5_PACKLIST=		auto/Gtk2/GladeXML/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
