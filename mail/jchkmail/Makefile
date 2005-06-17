# $NetBSD: Makefile,v 1.7 2005/06/17 04:49:47 jlam Exp $
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

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
