# $NetBSD: Makefile,v 1.16 2004/10/03 00:12:53 tv Exp $

DISTNAME=	libesmtp-1.0.3r1
PKGNAME=	${DISTNAME:S/r1//}
PKGREVISION=	1
CATEGORIES=	mail devel
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.stafford.uklinux.net/libesmtp/
COMMENT=	Library to manage posting of electronic mail

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-all
CONFIGURE_ARGS+=	--disable-isoc

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

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
#
post-buildlink:
	if [ ! -f /usr/include/des.h ]; then \
		${LN} -s ${SSLBASE}/include/openssl/des.h \
			${BUILDLINK_DIR}/include; \
	fi

.include "../../mk/bsd.pkg.mk"
