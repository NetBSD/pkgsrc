# $NetBSD: Makefile,v 1.4 2002/09/21 11:00:47 jlam Exp $
#

DISTNAME=	gtk-doc-0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/docs/rdp/

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	tools for authors of the GTK+ reference documentation

DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
DEPENDS+=	jade-[0-9]*:../../textproc/jade

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
