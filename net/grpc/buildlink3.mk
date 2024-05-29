# $NetBSD: buildlink3.mk,v 1.21 2024/05/29 16:35:19 adam Exp $

BUILDLINK_TREE+=	grpc

.if !defined(GRPC_BUILDLINK3_MK)
GRPC_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.grpc+=	grpc>=1.11.0
BUILDLINK_ABI_DEPENDS.grpc+=	grpc>=1.64.0
BUILDLINK_PKGSRCDIR.grpc?=	../../net/grpc

BUILDLINK_FILES.grpc+=	bin/grpc_cpp_plugin
BUILDLINK_FILES.grpc+=	bin/grpc_csharp_plugin
BUILDLINK_FILES.grpc+=	bin/grpc_node_plugin
BUILDLINK_FILES.grpc+=	bin/grpc_objective_c_plugin
BUILDLINK_FILES.grpc+=	bin/grpc_php_plugin
BUILDLINK_FILES.grpc+=	bin/grpc_python_plugin
BUILDLINK_FILES.grpc+=	bin/grpc_ruby_plugin

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.endif	# GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-grpc
