# $NetBSD: Makefile,v 1.1.1.1 2007/01/03 15:06:02 obache Exp $

DISTNAME=	ipa_sdb-1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://ipa-system.sourceforge.net/modules/ipa_sdb/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/modules/ipa_sdb/
COMMENT=	IPA simple database module

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=-with-mandir-ru=ru

.include "options.mk"

.include "../../sysutils/ipa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
