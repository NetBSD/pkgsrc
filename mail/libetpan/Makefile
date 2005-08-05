# $NetBSD: Makefile,v 1.4 2005/08/05 19:29:56 xtraeme Exp $
#

DISTNAME=		libetpan-0.38
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://libetpan.sourceforge.net/
COMMENT=		Really nice mail library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
