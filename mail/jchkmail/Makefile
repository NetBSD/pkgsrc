# $NetBSD: Makefile,v 1.5 2004/05/09 21:14:42 snj Exp $
#

DISTNAME=		jchkmail-1.3.1a
CATEGORIES=		mail
MASTER_SITES=		http://j-chkmail.ensmp.fr/download/

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://j-chkmail.ensmp.fr/
COMMENT=		Behavior-based virus and spam milter for Sendmail

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-rc-dir=${LOCALBASE}/etc/rc.d		\
			--with-conf-dir=${LOCALBASE}/etc/jchkmail

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
