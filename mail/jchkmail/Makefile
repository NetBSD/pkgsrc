# $NetBSD: Makefile,v 1.1.1.1 2003/09/22 14:33:35 manu Exp $
#

DISTNAME=		jchkmail-1.3.1a
CATEGORIES=		mail
MASTER_SITES=		http://j-chkmail.ensmp.fr/download/

MAINTAINER=		manu@netbsd.org
HOMEPAGE=		http://j-chkmail.ensmp.fr/
COMMENT=		Behavior-based virus and spam milter for Sendmail

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-rc-dir=${LOCALBASE}/etc/rc.d		\
			--with-conf-dir=${LOCALBASE}/etc/jchkmail

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
