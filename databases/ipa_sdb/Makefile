# $NetBSD: Makefile,v 1.7 2012/10/02 21:25:19 asau Exp $

DISTNAME=	ipa_sdb-1.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipa-system/modules/ipa_sdb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/modules/ipa_sdb/
COMMENT=	IPA simple database module
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS+=	--with-mandir-ru=ru

.include "options.mk"

.include "../../sysutils/ipa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
