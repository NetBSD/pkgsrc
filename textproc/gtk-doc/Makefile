# $NetBSD: Makefile,v 1.5 2003/07/17 22:54:18 grant Exp $
#

DISTNAME=	gtk-doc-0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/docs/rdp/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	tools for authors of the GTK+ reference documentation

DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
DEPENDS+=	jade-[0-9]*:../../textproc/jade

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
