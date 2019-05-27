# $NetBSD: Makefile,v 1.16 2019/05/27 15:18:28 bsiegert Exp $

COMMENT=	Go generated proto packages
PKGREVISION=	7

DEPENDS+=	go-genproto-googleapis-rpc-[0-9]*:../../misc/go-genproto-googleapis-rpc

.include "Makefile.common"

REPLACE_SH+=		regen.sh

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../net/go-grpc/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"

pre-configure:
	${RM} -rf ${WRKSRC}/googleapis/rpc

.include "../../mk/bsd.pkg.mk"
