# $NetBSD: Makefile,v 1.2 2002/02/05 11:11:03 martti Exp $
#

DISTNAME=	gtk-doc-0.9
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
