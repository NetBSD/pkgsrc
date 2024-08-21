# $NetBSD: Makefile,v 1.1 2024/08/21 13:02:47 gdt Exp $

DISTNAME=	bulk-test-erlang-20240821
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

# Feel free to add packages without asking.
MAINTAINER=	gdt@NetBSD.org
COMMENT=	Meta-package for testing erlang

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# Large programs
DEPENDS+=	ejabberd-[0-9]*:../../chat/ejabberd
DEPENDS+=	yaws-[0-9]*:../../www/yaws

# Libraries not covered by a large program
DEPENDS+=	erlang-doc-[0-9]*:../../lang/erlang-doc
DEPENDS+=	erlang-fs-[0-9]*:../../devel/erlang-fs
DEPENDS+=	erlang-goldrush-[0-9]*:../../sysutils/erlang-goldrush
DEPENDS+=	erlang-iconv-[0-9]*:../../converters/erlang-iconv
DEPENDS+=	erlang-man-[0-9]*:../../lang/erlang-man
DEPENDS+=	erlang-p1_xmlrpc-[0-9]*:../../textproc/erlang-p1_xmlrpc

.include "../../mk/bsd.pkg.mk"
