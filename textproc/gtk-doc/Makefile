# $NetBSD: Makefile,v 1.1.1.1 2002/01/31 08:13:06 martti Exp $
#

DISTNAME=	gtk-doc-0.8
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/docs/rdp/

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	tools for authors of the GTK+ reference documentation

DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
DEPENDS+=	jade-[0-9]*:../../textproc/jade

GNU_CONFIGURE=	YES
USE_PERL5=	YES

.include "../../mk/bsd.pkg.mk"
