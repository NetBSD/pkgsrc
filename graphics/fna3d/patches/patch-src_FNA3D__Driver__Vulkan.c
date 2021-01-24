$NetBSD: patch-src_FNA3D__Driver__Vulkan.c,v 1.1 2021/01/24 19:03:47 maya Exp $

Match the headers in vulkan-headers

--- src/FNA3D_Driver_Vulkan.c.orig	2021-01-01 16:22:56.000000000 +0000
+++ src/FNA3D_Driver_Vulkan.c
@@ -4444,7 +4444,7 @@ static void VULKAN_INTERNAL_SubmitComman
 	/* Present, if applicable */
 	if (present && acquireSuccess)
 	{
-		if (renderer->physicalDeviceDriverProperties.driverID == VK_DRIVER_ID_GGP_PROPRIETARY)
+		if (renderer->physicalDeviceDriverProperties.driverID == VK_DRIVER_ID_GGP_PROPRIETARY_KHR)
 		{
 			const void* token = SDL_GetWindowData(
 				(SDL_Window*) renderer->presentOverrideWindowHandle,
