# $NetBSD: Makefile,v 1.2 2007/01/22 13:10:41 obache Exp $

DISTNAME=	ipa_sdb-1.0.1
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://ipa-system.sourceforge.net/modules/ipa_sdb/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/modules/ipa_sdb/
COMMENT=	IPA simple database module

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS+=	--with-mandir-ru=ru

.include "options.mk"

.include "../../sysutils/ipa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
