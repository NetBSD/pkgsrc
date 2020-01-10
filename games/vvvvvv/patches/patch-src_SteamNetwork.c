$NetBSD: patch-src_SteamNetwork.c,v 1.1 2020/01/10 18:27:18 nia Exp $

Don't depend on proprietary steam libs

--- src/SteamNetwork.c.orig	2020-01-10 16:45:29.000000000 +0000
+++ src/SteamNetwork.c
@@ -15,10 +15,8 @@
 #define NETWORK_LIBRARY "steam_api.dll"
 #elif defined(__APPLE__)
 #define NETWORK_LIBRARY "libsteam_api.dylib"
-#elif defined(__linux__)
-#define NETWORK_LIBRARY "libsteam_api.so"
 #else
-#error NETWORK_LIBRARY: Unrecognized platform!
+#define NETWORK_LIBRARY "libsteam_api.so"
 #endif
 
 /* Function Pointer Types */
@@ -97,68 +95,6 @@ static void ClearPointers()
 
 int NETWORK_init()
 {
-	intptr_t steamClient;
-	int32_t steamUser, steamPipe;
-
-	libHandle = SDL_LoadObject(NETWORK_LIBRARY);
-	if (!libHandle)
-	{
-		printf("%s not found!\n", NETWORK_LIBRARY);
-		return 0;
-	}
-
-	#define LOAD_FUNC(name) \
-		name = (name##Func) SDL_LoadFunction(libHandle, #name); \
-		if (!name) \
-		{ \
-			printf("%s symbol %s not found!\n", NETWORK_LIBRARY, #name); \
-			ClearPointers(); \
-			return 0; \
-		}
-	LOAD_FUNC(SteamAPI_Init)
-	LOAD_FUNC(SteamAPI_Shutdown)
-	LOAD_FUNC(SteamAPI_RunCallbacks)
-	LOAD_FUNC(SteamInternal_CreateInterface)
-	LOAD_FUNC(SteamAPI_GetHSteamUser)
-	LOAD_FUNC(SteamAPI_GetHSteamPipe)
-	LOAD_FUNC(SteamAPI_ISteamClient_GetISteamUserStats)
-	LOAD_FUNC(SteamAPI_ISteamUserStats_RequestCurrentStats)
-	LOAD_FUNC(SteamAPI_ISteamUserStats_StoreStats)
-	LOAD_FUNC(SteamAPI_ISteamUserStats_GetStat)
-	LOAD_FUNC(SteamAPI_ISteamUserStats_SetStat)
-	LOAD_FUNC(SteamAPI_ISteamUserStats_SetAchievement)
-	#undef LOAD_FUNC
-
-	if (!SteamAPI_Init())
-	{
-		printf("Steamworks not initialized!\n");
-		ClearPointers();
-		return 0;
-	}
-	steamClient = SteamInternal_CreateInterface(VVVVVV_STEAMCLIENT);
-	steamUser = SteamAPI_GetHSteamUser();
-	steamPipe = SteamAPI_GetHSteamPipe();
-	if (!steamClient || !steamUser || !steamPipe)
-	{
-		SteamAPI_Shutdown();
-		printf(VVVVVV_STEAMCLIENT " not created!\n");
-		ClearPointers();
-		return 0;
-	}
-	steamUserStats = SteamAPI_ISteamClient_GetISteamUserStats(
-		steamClient,
-		steamUser,
-		steamPipe,
-		VVVVVV_STEAMUSERSTATS
-	);
-	if (!steamUserStats)
-	{
-		SteamAPI_Shutdown();
-		printf(VVVVVV_STEAMUSERSTATS " not created!\n");
-		ClearPointers();
-		return 0;
-	}
-	SteamAPI_ISteamUserStats_RequestCurrentStats(steamUserStats);
 	return 1;
 }
 
