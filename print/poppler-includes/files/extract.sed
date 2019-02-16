1,/if(ENABLE_UNSTABLE_API_ABI_HEADERS)/ d
/^endif/,$ d
s/^  *\([a-z]*\/[A-Za-z0-9_-]*\.h\).*/\1/p
