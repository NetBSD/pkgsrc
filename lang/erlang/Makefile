# $NetBSD: Makefile,v 1.8 2003/09/27 17:07:36 grant Exp $

DISTNAME=		otp_src_R9C-0
PKGNAME=		erlang-9.2
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
USE_GMAKE=		yes
USE_JAVA=		yes
USE_JAVA2=		yes

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
