# $NetBSD: Makefile,v 1.4 2003/07/17 21:44:18 grant Exp $

DISTNAME=		otp_src_R9B-1
PKGNAME=		erlang-9.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.erlang.org
COMMENT=		concurrent functional programming language

DIST_SUBDIR=		erlang

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/pthread.buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
