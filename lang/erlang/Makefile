# $NetBSD: Makefile,v 1.13 2004/06/28 17:39:46 abs Exp $

DISTNAME=		otp_src_R9C-0
PKGNAME=		erlang-9.2
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Concurrent functional programming language

DIST_SUBDIR=		erlang

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_JAVA=		yes
USE_JAVA2=		yes

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
