# $NetBSD: Makefile,v 1.7 2003/09/24 09:12:19 xtraeme Exp $

DISTNAME=	libesmtp-1.0.1
CATEGORIES=	mail devel
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.stafford.uklinux.net/libesmtp/
COMMENT=	Library to manage posting of electronic mail

USE_BUILDLINK2=	yes
USE_GMAKE=      yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-all
CONFIGURE_ARGS+=        --disable-isoc

# XXX Evil hack to deal with the openssl/des.h interface change
# between 0.96 and 0.97
# This pkg needs the old API. It includes <des.h> (by patch).
# We assume 2 cases:
# a) We are on NetBSD-current which has a non-backward-compatible
#    openssl-0.97, but a <des.h> providing the old interface.
#    So the pkg sees the backward-compatibility header.
# b) Everything else - we have an old openssl or a pkg version
#    which is backward-compatible. Create a symlink to find
#    <openssl/des.h> as <des.h>.
post-buildlink:
	if [ ! -f /usr/include/des.h ]; then \
		${LN} -s ${BUILDLINK_DIR}/include/openssl/des.h \
			${BUILDLINK_DIR}/include; \
	fi

.include "../../mk/pthread.buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
