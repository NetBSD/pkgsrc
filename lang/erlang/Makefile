# $NetBSD: Makefile,v 1.12 2004/03/26 02:27:42 wiz Exp $

DISTNAME=		otp_src_R9C-0
PKGNAME=		erlang-9.2
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Concurrent functional programming language

DIST_SUBDIR=		erlang

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_JAVA=		yes
USE_JAVA2=		yes

.include "../../security/openssl/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
