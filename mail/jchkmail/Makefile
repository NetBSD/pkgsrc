# $NetBSD: Makefile,v 1.8 2006/01/08 16:26:22 joerg Exp $
#

DISTNAME=		jchkmail-1.3.1a
CATEGORIES=		mail
MASTER_SITES=		http://j-chkmail.ensmp.fr/download/

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://j-chkmail.ensmp.fr/
COMMENT=		Behavior-based virus and spam milter for Sendmail

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-rc-dir=${PREFIX}/etc/rc.d		\
			--with-conf-dir=${PREFIX}/etc/jchkmail

PTHREAD_AUTO_VARS=	yes

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
